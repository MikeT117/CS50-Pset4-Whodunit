# Questions

## What's `stdint.h`?

Allows you to specify variable sizes which aides portability across platforms.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Specifies the number of bytes to use in an int, This is particularly useful whe n porting as an int in another platform could be 32bit, 12bit etc.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 Byte - 8 Bits, 4 Bytes 32 Bits, 4 Bytes - 32Bits, 2 Bytes 16 Bits

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

bfsize is the total size of the BMP, including the header. bisize is the numder of bytes required by the structure.

## What does it mean if `biHeight` is negative?

A negative biHeight indicates a top-down DIB, These cannot be compressed.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file cannot be found.

## Why is the third argument to `fread` always `1` in our code?

We are dealing with one fil.e at a time and therefore one element.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Sets the position of the stream to the given offset

## What is `SEEK_CUR`?

Moves thr file pointer to given location.

## Whodunit?

It was professor Plum with the candlestick in the library.
