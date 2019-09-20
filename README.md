# W3050
------------------------------------------------------------------------------
W3050 SDK development kit

## Building 
------------------------------------------------------------------------------
To build the source code:
```shell
cd w3050/w3050-10/mcu
gcc -c wlibc-hdlc-codec.c demo.c -I ../../inc -I ./ -U __APPLE__ -D __W8100__
```

# License
------------------------------------------------------------------------------
Copyright (c) 2017-2030, WindsBridge - http://windsbridge.com All rights reserved! 北京风桥科技有限公司保留所有权利!

[MIT license](LICENSE)

