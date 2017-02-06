compile: picmaker.c
	gcc picmaker.c -o picmaker -lm

run: picmaker
	./picmaker
	display image.ppm

convert:
	convert image.ppm image.png

clean:
	rm picmaker image.ppm image.png