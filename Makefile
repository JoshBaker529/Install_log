
CC:= g++
CFLAGS := -std=c++17 -Wall
OUT := log
FILES := driver.cpp Settings.h Settings.cpp

all: $(OUT)

$(OUT): $(FILES)
	$(CC) $(CFLAGS) $(FILES) 
	mv a.out $(OUT)

clean:
	rm -f $(OUT)

.PHONEY: all clean


