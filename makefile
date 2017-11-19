# Gilad Madmon
# 305132599

a.out: compileAll
	g++ *.o 
	rm -f *.o
	rm -f sources.txt

compileAll:
	find -name "*.cpp" > sources.txt
	g++ -c @sources.txt
