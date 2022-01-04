http://igoro.com/archive/gallery-of-processor-cache-effects/

```bash
clang or gcc -O3
```

我们基于这样的事实：
- l1-load => compute => l1-store：每一步花费的tick很少；
- mem->cache & cache->mem：每一步花费的tick较多；
可以得出这样的结论：
```C++
int[] arr = new int[64 * 1024 * 1024];

// Loop 1
for (int i = 0; i < arr.Length; i++) {
    arr[i] += 3;
}

// Loop 2
for (int i = 0; i < arr.Length; i += 16) {
    arr[i] += 3;
}
```
loop1和loop2花费的时间相当。因为时间主要花费在mem与cache的通信，而cache和core的通信忽略不计。
本质上：通过stride的load/store数组元素，测试load/store cache line的数量