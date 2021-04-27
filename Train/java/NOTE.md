1. slice 比较：go 不能重载运算符，也没有提供默认的比较函数，因此需要自己手动编写比较函数，或者使用reflect.Equal 进行底层比较
2. 不能用 get 值是 null 来判断 hashmap 里头是不是有这个 key，因为除了没有 key 之外，还有可能 key 对应的 value 为 null