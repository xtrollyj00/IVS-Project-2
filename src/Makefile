TARGET=wcalculator
ZIPFILE=xalexa09_xgurka00_xmagda03

.PHONY: clean makefile doc

all: $(TARGET)

$(TARGET): makefile
	cd ../build && make

makefile:
	cd ../build && qmake

pack:
	mkdir -p ../../$(ZIPFILE)
	mkdir -p ../../$(ZIPFILE)/doc
	mkdir -p ../../$(ZIPFILE)/install
	mkdir -p ../../$(ZIPFILE)/repo
	make doc
	cp -a ../docs/. ../../$(ZIPFILE)/doc
	make clean
	
	
doc:
	doxygen

run: $(TARGET)
	cd ../build && ./wcalculator

#profile:

clean: makefile
	cd ../build && make clean && rm -f $(TARGET) Makefile .qmake.stash
	rm -r ../docs
