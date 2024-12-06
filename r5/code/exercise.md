---
marp: true
math: mathjax
paginate: true
style: |
  section::after {
    content: attr(data-marpit-pagination) '/' attr(data-marpit-pagination-total);
  }

  .columns {
    display: grid;
    grid-template-columns: repeat(2, minmax(0, 1fr));
    gap: 1rem;
  }

---

# Recitation 5 Exercise

## From Xiao Liu

---

# Exercise 1
### Read the following code segments. Tell whether it can compile or not, if can, what's the output?

---

<div class="columns">
<div class="columns-left">

# Exercise 1.1

```c
#include <stdio.h>

int main(void){
  n += 5;
  printf("%d\n", n);

  return 0;
}  
```

</div>
<div class="columns-right">

# Exercise 1.2

```c
#include <stdio.h>

int n = 0;

int main(void) {
  n += 5;
  printf("%d\n", n);

  return 0;
}
```

</div>
</div>

---

<div class="columns">
<div class="columns-left">

# Exercise 1.3

```c
#include <stdio.h>

int n = 0;

int main(void) {
  int n;
  n += 5;

  printf("%d\n", n);

  return 0;
}
```

</div>
<div class="columns-right">

# Exercise 1.4

```c
#include <stdio.h>

int n = 0;

int main(void){
  int n = 1;

  n += 5;
  printf("%d\n", n);

  return 0;
}
```

</div>
</div>

---

<div class="columns">
<div class="columns-left">

# Exercise 1.5

```c
#include <stdio.h>

int n = 0;

int main(void) {
  extern int n;

  n += 5;
  printf("%d\n", n);

  return 0;
}
```

</div>
<div class="columns-right">

# Exercise 1.6

```c
#include <stdio.h>

int total(int x) {
  static int total = 0;

  total += x;
  return total;
}

int main(void) {
  total(5);
  total(10);
  printf("%d\n", total(15));
  return 0;
}
```

</div>
</div>

---

# Exercise 1.7

<div class="columns">
<div class="columns-left">

`library.h`:
```c
#ifndef LIBRARY_H
#define LIBRARY_H

int net_price(int price, int discount);
static int validate(int n);

#endif
```

`driver.c`: 
```c
#include "library.h"
int main(void) {
  int i, j;
  i = validate(-5);
  j = net_price(6, 2);
}
```

</div>

<div class="columns-right">


`library.c`:

```c
#include "library.h"

int net_price(int price, int discount) {
  return validate(price - discount);
}

static int validate(int n) {
  if (n < 0) 
    return 0;
  else       
    return n;
}
```
</div>
</div>

---

# Exercise 2
### Identify whether the header files and source files can separately be compiled. If can, can they link together?

---

# Exercise 2.1

<div class="columns">
<div class="columns-left">

`account.h`:
```c
#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACCT_OK      0
#define ACCT_INVALID 1
#define ACCT_CLOSED  2

int acct_status;

#endif
```

</div>

<div class="columns-right">

`account.c`:

```c
#include "account.h"

// Use acct_status
```

`driver.c`:

```c
#include "account.h"

// Use acct_status
```

</div>
</div>

---

# Exercise 2.2

<div class="columns">
<div class="columns-left">

`account.h`:
```c
#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACCT_OK      0
#define ACCT_INVALID 1
#define ACCT_CLOSED  2

// Don't define acct_status
// since that caused the problem

#endif
```

</div>

<div class="columns-right">

`account.c`:

```c
#include "account.h"

// Use acct_status

```

`driver.c`:

```c
#include "account.h"

// Use acct_status

```

</div>
</div>

---

# Exercise 2.3

<div class="columns">
<div class="columns-left">

`account.h`:
```c
#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACCT_OK      0
#define ACCT_INVALID 1
#define ACCT_CLOSED  2

// Don't define acct_status

#endif
```

</div>

<div class="columns-right">

`account.c`:

```c
#include "account.h"

int acct_status;

// Use acct_status
```

`driver.c`:

```c
#include "account.h"

// Use acct_status

```

</div>
</div>

---

# Exercise 2.4

<div class="columns">
<div class="columns-left">

`account.h`:
```c
#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACCT_OK      0
#define ACCT_INVALID 1
#define ACCT_CLOSED  2

extern int acct_status;

#endif
```

</div>

<div class="columns-right">

`account.c`:

```c
#include "account.h"

// Use acct_status
```

`driver.c`:

```c
#include "account.h"

// Use acct_status
```

</div>
</div>

---

# Exercise 2.5

<div class="columns">
<div class="columns-left">

`account.h`:
```c
#ifndef ACCOUNT_H
#define ACCOUNT_H

#define ACCT_OK      0
#define ACCT_INVALID 1
#define ACCT_CLOSED  2

extern int acct_status;

#endif
```

</div>

<div class="columns-right">

`account.c`:

```c
#include "account.h"

int acct_status = ACCT_OK;

// Use acct_status
```

`driver.c`:

```c
#include "account.h"

// Use acct_status
```

</div>
</div>

---

# Recitation 5 Exercise

## From Xiao Liu

