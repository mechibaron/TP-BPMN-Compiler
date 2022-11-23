all:
	script/build.sh

test:
	script/test.sh

clean:
	rm -r bin
	rm src/frontend/lexical-analysis/flex-scanner.c
	rm src/frontend/syntactic-analysis/bison-parser.c
	rm src/frontend/syntactic-analysis/bison-parser.h
	rm out.dot
dot:
	dot -Tsvg out.dot  -o out.svg