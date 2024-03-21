vektoriai.exe: v1.0.cpp ManoBib.cpp
	g++ -o vektoriai.exe v1.0.cpp ManoBib.cpp

list.exe: lv1.0.cpp ManoBibL.cpp
	g++ -o list.exe lv1.0.cpp ManoBibL.cpp

deque.exe: dv1.0.cpp ManoBibD.cpp
	g++ -o deque.exe dv1.0.cpp ManoBibD.cpp

runV: vektoriai.exe
	./vektoriai.exe

runL: list.exe
	./list.exe

runD: deque.exe
	./deque.exe

delete:
	del vektoriai.exe
	del list.exe
	del deque.exe
	del pazenge.txt
	del buki.txt