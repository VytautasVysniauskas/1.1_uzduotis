#pragma once
#include "Bibliotekos.h"

/**
 * @brief Bazinë klase, kuri atstovauja asmeniui.
 *
 * Si klasë apibrezia bendrus atributus ir metodus asmeniui.
 */
using namespace std;
using namespace std::chrono;

template<class T, class Allocator = std::allocator<T>>
class MyVector
{
private:
    using allocator_type = typename Allocator::template rebind<T>::other;
    using size_type = std::size_t;
    using pointer = T*;

    allocator_type alloc;
    pointer data_ptr;
    size_type sz;
    size_type cap;

public:
    using value_type = T;
    using difference_type = ptrdiff_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    MyVector() : alloc(), data_ptr(nullptr), sz(0), cap(0) {}

    MyVector(size_type count) : alloc(), data_ptr(nullptr), sz(count), cap(count) {
        data_ptr = alloc.allocate(count);
        for (size_type i = 0; i < count; ++i) {
            alloc.construct(data_ptr + i);
        }
    }

    MyVector(size_type count, const T& value) : alloc(), data_ptr(nullptr), sz(count), cap(count) {
        data_ptr = alloc.allocate(count);
        for (size_type i = 0; i < count; ++i) {
            alloc.construct(data_ptr + i, value);
        }
    }

    ~MyVector() {
        clear();
        alloc.deallocate(data_ptr, cap);
    }

    MyVector(const MyVector& other) : alloc(), data_ptr(nullptr), sz(0), cap(0) {
        reserve(other.sz);
        for (const auto& elem : other) {
            push_back(elem);
        }
    }

    MyVector(MyVector&& other) noexcept : alloc(std::move(other.alloc)), data_ptr(other.data_ptr), sz(other.sz), cap(other.cap) {
        other.data_ptr = nullptr;
        other.sz = 0;
        other.cap = 0;
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            clear();
            reserve(other.sz);
            for (const auto& elem : other) {
                push_back(elem);
            }
        }
        return *this;
    }

    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            clear();
            alloc.deallocate(data_ptr, cap);

            data_ptr = other.data_ptr;
            sz = other.sz;
            cap = other.cap;

            other.data_ptr = nullptr;
            other.sz = 0;
            other.cap = 0;
        }
        return *this;
    }

    allocator_type& get_allocator() noexcept { return alloc; }

    reference at(size_type pos) {
        if (pos >= sz) throw std::out_of_range("Index out of range");
        return data_ptr[pos];
    }

    const_reference at(size_type pos) const {
        if (pos >= sz) throw std::out_of_range("Index out of range");
        return data_ptr[pos];
    }

    reference operator[](size_type pos) { return data_ptr[pos]; }
    const_reference operator[](size_type pos) const { return data_ptr[pos]; }
    reference front() { return *begin(); }
    const_reference front() const { return *begin(); }
    reference back() { return *(end() - 1); }
    const_reference back() const { return *(end() - 1); }
    T* data() noexcept { return data_ptr; }
    const T* data() const noexcept { return data_ptr; }

    iterator begin() noexcept { return data_ptr; }
    const_iterator begin() const noexcept { return data_ptr; }
    iterator end() noexcept { return data_ptr + sz; }
    const_iterator end() const noexcept { return data_ptr + sz; }
    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

    bool empty() const noexcept { return sz == 0; }
    size_type size() const noexcept { return sz; }
    size_type max_size() const noexcept { return std::allocator_traits<Allocator>::max_size(alloc); }

    void reserve(size_type new_cap) {
        if (new_cap > cap) {
            pointer new_data = alloc.allocate(new_cap);
            std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), new_data);
            clear();
            alloc.deallocate(data_ptr, cap);
            data_ptr = new_data;
            cap = new_cap;
        }
    }

    size_type capacity() const noexcept { return cap; }

    void shrink_to_fit() {
        if (sz < cap) {
            pointer new_data = alloc.allocate(sz);
            std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), new_data);
            clear();
            alloc.deallocate(data_ptr, cap);
            data_ptr = new_data;
            cap = sz;
        }
    }

    void clear() noexcept {
        for (size_type i = 0; i < sz; ++i) {
            alloc.destroy(data_ptr + i);
        }
        sz = 0;
    }

    iterator insert(const_iterator pos, const T& value) {
        size_type index = std::distance(begin(), const_cast<iterator>(pos));
        if (sz >= cap) reserve(sz + 1);
        std::move_backward(data_ptr + index, data_ptr + sz, data_ptr + sz + 1);
        alloc.construct(data_ptr + index, value);
        ++sz;
        return begin() + index;
    }

    iterator insert(const_iterator pos, size_type count, const T& value) {
        size_type index = std::distance(begin(), const_cast<iterator>(pos));
        if (sz + count > cap) reserve(sz + count);
        std::move_backward(data_ptr + index, data_ptr + sz, data_ptr + sz + count);
        std::fill_n(data_ptr + index, count, value);
        sz += count;
        return begin() + index;
    }

    template<class InputIt>
    iterator insert(const_iterator pos, InputIt first, InputIt last) {
        size_type count = std::distance(first, last);
        size_type index = std::distance(begin(), const_cast<iterator>(pos));
        if (sz + count > cap) reserve(sz + count);
        std::move_backward(data_ptr + index, data_ptr + sz, data_ptr + sz + count);
        std::copy(first, last, data_ptr + index);
        sz += count;
        return begin() + index;
    }

    iterator erase(const_iterator pos) {
        size_type index = std::distance(begin(), const_cast<iterator>(pos));
        alloc.destroy(data_ptr + index);
        std::move(data_ptr + index + 1, data_ptr + sz, data_ptr + index);
        --sz;
        return begin() + index;
    }

    iterator erase(const_iterator first, const_iterator last) {
        size_type first_index = std::distance(begin(), const_cast<iterator>(first));
        size_type last_index = std::distance(begin(), const_cast<iterator>(last));
        for (size_type i = first_index; i < last_index; ++i) {
            alloc.destroy(data_ptr + i);
        }
        std::move(data_ptr + last_index, data_ptr + sz, data_ptr + first_index);
        sz -= (last_index - first_index);
        return begin() + first_index;
    }

    void push_back(const T& value) {
        if (sz >= cap) reserve(sz + 1);
        alloc.construct(data_ptr + sz, value);
        ++sz;
    }

    void push_back(T&& value) {
        if (sz >= cap) reserve(sz + 1);
        alloc.construct(data_ptr + sz, std::move(value));
        ++sz;
    }

    template<class... Args>
    reference emplace_back(Args&&... args) {
        if (sz >= cap) reserve(sz + 1);
        alloc.construct(data_ptr + sz, std::forward<Args>(args)...);
        ++sz;
        return back();
    }

    void pop_back() {
        if (sz > 0) {
            --sz;
            alloc.destroy(data_ptr + sz);
        }
    }

    void resize(size_type count) {
        if (count < sz) {
            for (size_type i = count; i < sz; ++i) {
                alloc.destroy(data_ptr + i);
            }
        }
        else if (count > sz) {
            reserve(count);
            for (size_type i = sz; i < count; ++i) {
                alloc.construct(data_ptr + i);
            }
        }
        sz = count;
    }

    void resize(size_type count, const T& value) {
        if (count < sz) {
            for (size_type i = count; i < sz; ++i) {
                alloc.destroy(data_ptr + i);
            }
        }
        else if (count > sz) {
            reserve(count);
            for (size_type i = sz; i < count; ++i) {
                alloc.construct(data_ptr + i, value);
            }
        }
        sz = count;
    }

    void swap(MyVector& other) noexcept {
        std::swap(alloc, other.alloc);
        std::swap(data_ptr, other.data_ptr);
        std::swap(sz, other.sz);
        std::swap(cap, other.cap);
    }
};


class zmogus {
protected:
    string name;
    string surname;
    
public:
    /**
    * @brief Numatytasis konstruktorius.
    */
    zmogus() : name(""), surname("") {}
    /**
    * @brief Konstruktorius su vardo parametru.
    *
    * @param n - Asmens vardas.
    */
    zmogus(const string& n) : name(n), surname("") {}
    /**
     * @brief Konstruktorius su vardo ir pavardës parametrais.
     *
     * @param n - Asmens vardas.
     * @param s - Asmens pavarde.
     */
    zmogus(const string& n, const string& s) : name(n), surname(s) {}

    virtual ~zmogus() {} /**< Virtualus destruktorius. */

    /**
    * @brief Abstraktus metodas, skirtas atspausdinti informacija apie asmeni.
    *
    * Si metoda privalo igyvendinti isvestinës klases.
    */

    virtual void printInfo() const = 0;

    /**
     * @brief Gauna asmenio vardà.
     *
     * @return Asmens vardas.
     */

    const string& getName() const { return name; }
    /**
     * @brief Gauna asmenio pavarde.
     *
     * @return Asmens pavarde.
     */
    const string& getSurname() const { return surname; }
};
/**
 * @brief Klase, kuri atstovauja mokiniui.
 *
 * Si klase isplecia bazine klase zmogus ir prideda specifinius mokinio atributus ir metodus.
 */

class mokiniai : public zmogus {
private:
    std::string name; /**< Mokinio vardas */
    std::string surname; /**< Mokinio pavarde */
    std::vector<int> ndRez; /**< Mokinio namu darbu rezultatai */
    int egzRez; /**< Mokinio galutinis egzamino rezultatas */
    double average; /**< Mokinio vidurkis */
    double med; /**< Mokinio mediana */

public:

    // Konstruktoriu, destruktoriu ir priskyrimo operatoriu deklaracijos...

    // Getteriu ir setteriu deklaracijos...
    mokiniai() : egzRez(0), average(0), med(0) {}
    mokiniai(const std::string& n) : name(n), egzRez(0), average(0), med(0) {}
    mokiniai(const std::string& n, const std::string& s) : name(n), surname(s), egzRez(0), average(0), med(0) {}
    mokiniai(const std::string& n, const std::string& s, int egz) : name(n), surname(s), egzRez(egz), average(0), med(0) {}
    mokiniai(const std::string& n, const std::string& s, int egz, double av) : name(n), surname(s), egzRez(egz), average(av), med(0) {}
    mokiniai(const std::string& n, const std::string& s, int egz, double av, double m) : name(n), surname(s), egzRez(egz), average(av), med(m) {}

    mokiniai(const mokiniai& other) : name(other.name), surname(other.surname), ndRez(other.ndRez), egzRez(other.egzRez), average(other.average), med(other.med) {}

    mokiniai(mokiniai&& other) noexcept : name(std::move(other.name)), surname(std::move(other.surname)), ndRez(std::move(other.ndRez)), egzRez(other.egzRez), average(other.average), med(other.med) {
        other.egzRez = 0;
        other.average = 0;
        other.med = 0;
    }

    mokiniai& operator=(const mokiniai& other) {
        if (this != &other) {
            name = other.name;
            surname = other.surname;
            ndRez = other.ndRez;
            egzRez = other.egzRez;
            average = other.average;
            med = other.med;
        }
        return *this;
    }

    mokiniai& operator=(mokiniai&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            surname = std::move(other.surname);
            ndRez = std::move(other.ndRez);
            egzRez = other.egzRez;
            average = other.average;
            med = other.med;
            other.egzRez = 0;
            other.average = 0;
            other.med = 0;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const mokiniai& m);
    friend std::istream& operator>>(std::istream& is, mokiniai& m);

    const std::string& getName() const { return name; }
    const std::string& getSurname() const { return surname; }
    const std::vector<int>& getNdRez() const { return ndRez; }
    int getEgzRez() const { return egzRez; }
    double getAverage() const { return average; }
    double getMed() const { return med; }

    void setName(const std::string& n) { name = n; }
    void setSurname(const std::string& s) { surname = s; }
    void setEgzRez(int egz) { egzRez = egz; }
    void setNdRez(int nd) { ndRez.push_back(nd); }
    void setAverage(double ndRezAvg, double egz) { average = 0.4 * ndRezAvg + 0.6 * egz; }
    void setAverage(double av) { average = av; }
    void setMed(double vid1, double vid2) { med = (vid1 + vid2) / 2; }
    void setMed(double m) { med = m; }

    /**
    * @brief Abstraktus metodas, skirtas atspausdinti informacija apie mokini.
    *
    * Perraso bazines klases metoda.
    */

    void printInfo() const override
    {
        cout << "Name: " << getName() << ", Surname: " << getSurname() << std::endl;
    }
};

// Funkciju prototipu deklaracijos, jos aprasytos ManoBib.cpp faile.


void spauzdinimasFaile(MyVector<mokiniai>&, MyVector<mokiniai>&, int, duration<double>&);
void spauzdinimasEkrane(MyVector<mokiniai>&, int);
void vidurys(MyVector<mokiniai>&, int);
int skaitymasRanka(MyVector<mokiniai>&, int);
int skaitymasFailo(MyVector<mokiniai>&, int, duration<double>&);
void rikiavimas(MyVector<mokiniai>&, int, char);
void duomenuGeneravimas(int);
void kiekGeneruoti();
