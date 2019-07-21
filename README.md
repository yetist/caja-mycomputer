# 编译方法

```
mkdir build
cd build/
meson setup --prefix=/usr --sysconfdir=/etc
ninja 
DESTDIR=/tmp/abc ninja install 
```
