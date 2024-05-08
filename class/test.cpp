#include "pch.h"
#include "../../Bibliotekos.h"

class ManoBibTest : public ::testing::Test {
protected:

    std::vector<mokiniai> M;
    std::vector<mokiniai> B;

    void SetUp() override
    {
        random_device rd;
        mt19937 gen(rd());
        for (int x = 0; x < 1000; x++)
        {
            string vardas = "Vardas" + to_string(x);
            M[x].setName(vardas);
            string surname = "Pavarde" + to_string(x);
            M[x].setSurname(surname);

            uniform_int_distribution<int> avgGen(1, 10);
            M[x].setAverage(avgGen(gen));
            uniform_int_distribution<int> medGen(1, 10);
            M[x].setMed(medGen(gen));
        }
    }

    
    void TearDown() override 
    {
        M.clear();
        B.clear();
    }
};

TEST_F(ManoBibTest, SpauzdinimasFaileTest) {
    std::vector<mokiniai> M;
    std::vector<mokiniai> B;
    int dydis = 5;
    std::chrono::duration<double> laikas3;

    spauzdinimasFaile(M, B, dydis, laikas3);

    ASSERT_FALSE(M.empty()); 
    ASSERT_FALSE(B.empty()); 

    EXPECT_EQ(M.size() + B.size(), dydis);
}

class RikiavimasTest : public ::testing::Test {
protected:

    std::vector<mokiniai> M;

    void SetUp() override 
    {
        random_device rd;
        mt19937 gen(rd());
        for (int x = 0; x < 1000; x++)
        {
            string vardas = "Vardas" + to_string(x);
            M[x].setName(vardas);
            string surname = "Pavarde" + to_string(x);
            M[x].setSurname(surname);

            uniform_int_distribution<int> avgGen(1, 10);
            M[x].setAverage(avgGen(gen));
            uniform_int_distribution<int> medGen(1, 10);
            M[x].setMed(medGen(gen));
        }
    }

    void TearDown() override 
    {
        M.clear();
    }
};


TEST_F(RikiavimasTest, RikiavimasTest) {
   
    int dydis = M.size();
    char pasirinkimas = 'V'; 

    rikiavimas(M, dydis, pasirinkimas);

    
    EXPECT_TRUE(std::is_sorted(M.begin(), M.end(), [](const mokiniai& a, const mokiniai& b)
        {
        return a.getName() < b.getName();
        }));
}
