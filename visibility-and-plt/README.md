This just demonstrates how a non-exported function avoids the PLT.

See this excerpt from `objdump -DC -M intel libshared.so`:

```
0000000000001177 <using_local_func()>:
    1177:       f3 0f 1e fa             endbr64
    117b:       55                      push   rbp
    117c:       48 89 e5                mov    rbp,rsp
    117f:       e8 d5 ff ff ff          call   1159 <local_func()>
    1184:       5d                      pop    rbp
    1185:       c3                      ret

0000000000001186 <using_global_func()>:
    1186:       f3 0f 1e fa             endbr64
    118a:       55                      push   rbp
    118b:       48 89 e5                mov    rbp,rsp
    118e:       e8 fd fe ff ff          call   1090 <global_func()@plt>
    1193:       5d                      pop    rbp
    1194:       c3                      ret
```
