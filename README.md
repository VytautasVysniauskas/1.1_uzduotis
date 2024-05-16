# 1_uzduotis

Vektoriu std::vector ir savo sukurtu MyVector push_back laikai buvo tikrinami, stai ju rezultatai:
|             	| **std::vector** 	| **MyVector** 	|
|-------------	|:---------------:	|:------------:	|
| 100 000     	|         0.00152 	|      0.00100 	|
| 1 000 000   	|         0.01230 	|      0.01023 	|
| 10 000 000  	|         0.12099 	|      0.09233 	|
| 100 000 000 	|         1.17986 	|      0.91796 	|
