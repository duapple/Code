#ifndef __SAL_H__
#define __SAL_H__

#define SAL_OK 0
#define SAL_ERR 1
#define SAL_MEM 2
#define SAL_ERR_P_NULL 3
#define SAL_NULL -1

#ifndef SAL_CHECK_P_NULL
#define SAL_CHECK_P_NULL(p)    \
    if (NULL == p)             \
    {                          \
        return SAL_ERR_P_NULL; \
    }
#endif

#endif /* __SAL_H__ */