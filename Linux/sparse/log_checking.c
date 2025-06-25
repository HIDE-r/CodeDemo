#include <stdio.h>

// 这个宏在c库中已经定义
// #define __always_inline                 inline __attribute__((__always_inline__))

// sparse 调用时会传入这个宏, 作为开启的标识
#ifdef __CHECKER__
# define __must_hold(x)	__attribute__((context(x,1,1)))
# define __acquire(x) __context__(x,1)
# define __release(x) __context__(x,-1)
#else
# define __must_hold(x)
# define __acquire(x) (void)0
# define __release(x) (void)0
#endif

static __always_inline int lock(void)
{
    __acquire(TEST); // 表示获取锁
}

static __always_inline int unlock(void)
{
    __release(TEST); // 表示释放锁
}

static int func(void)
{
    // 表示这里必须持有锁
    __must_hold(TEST);
    return 0;
}


int main(int argc, char *argv[])
{
    lock();

    /* TODO something */
    func();

    unlock();
    return 0;
}
