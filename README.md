# W3050
W3050 SDK development

## Building 
To build the source code:
```shell
cd w3050/w3050-10/mcu
gcc -c wlibc-hdlc-codec.c demo.c -I ../../inc -I ./ -U __APPLE__ -D __W8100__
```

# License
[MIT license](LICENSE)
