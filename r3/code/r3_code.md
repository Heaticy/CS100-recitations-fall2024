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

# Recitation 3 Code
## From Xiao Liu

---

# Exercise 1

Sincer `i` is defined globally, it is initialized with default value `0`. The `else` block is executed as the expression within if evalutes to false. Therefore, the `else` block gets executed.

---

# Exercise 2

Output:
```
func(1): case 1, case 2, case 3.
func(2): case 2, case 3.
func(3): case 3.
func(4): case 4, case 5 or case 6, default.
func(5): case 5 or case 6, default.
func(6): case 5 or case 6, default.
func(7): default.
func(8): default.
```

---

# Exercise 3

Initially i = 0. Since case 0 is true i becomes 5, and since there is no break statement till last statement of switch block, i becomes 16. Now in next iteration no case is true, so execution goes to default and i becomes 21. In C, if one case is true switch block is executed until it finds break statement. If no break statement is present all cases are executed after the true case.

---

# Exercise 4

In for loop, mentioning expression is optional. `>>=` is a composite operator. It shifts the binary representation of the value by 1 to the right and assigning the resulting value to the same value. The for loop is executed until value of varible `i` doesn't drop to `0`.

--- 

# Exercise 5

The program goes in an infinite loop sicne `n` is never zero when loop condition `n != 0` is checked. `n` changes like 9 7 5 3 1 -1 -3 -5 -7 -9 ...

---

# Exercise 6

There is a bug in the above program. It goes inside the do-while loop for `c = 0`. Also as the increment is post increment, so `no / 0` will create a divide by 0 error. So it fails during runtime.

---

# Exercise 8.1

```c
#define MAX(A, B) A < B ? B : A
```

After this, every `MAX(expr1, expr2)` will be replaced with `expr1 < expr2 ? expr2 : expr1`.

```c
int i = 10, j = 15;
int k = MAX(i, j) + 1;
```

It gets replaced as:

```c
int i = 10, j = 15;
int k = i < j ? j : i + 1; // i < j ? j : (i + 1)
```

---

# Exercise 8.2

```c
#define MAX(A, B) (A < B ? B : A)
```

Is adding one pair of parentheses enough?

```c
int i = 10, j = 15;
int k = MAX(i, i & j); // Comparing i and i & j
```

It gets replaced as:

```c
int i = 10, j = 15;
int k = (i < i & j ? i & j : i); // (i < i) & j
```

Operator precedence: comparison operators > bitwise AND, bitwise XOR, bitwise OR.

---

# Exercise 8.3

```c
#define MAX(A, B) ((A) < (B) ? (B) : (A))
```

Adding parentheses everywhere should fix it, right?

```c
int i = 10, j = 15;
int k = MAX(i, ++j);
```

It gets replaced as:

```c
int i = 10, j = 15;
int k = ((i) < (++j) ? (++j) : (i));
```

`j` might get incremented twice!

---

# Exercise 9.1

```c
#include <stdio.h>

int main(void) {
  n += 5;
  printf("%d\n", n);

  return 0;
}  
```

- It does **NOT** compile since `n` is not declared in the scope of `main()`.

---

# Exercise 9.2

```c
#include <stdio.h>

int n = 0;

int main(void) {
  n += 5;
  printf("%d\n", n);

  return 0;
}
```

- It compiles since `n` has file scope.

- The output is `5`.

---

# Exercise 9.3

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

- It compiles since there is an `n` is with file scope and an `n` with local scope.
- Print the local scope `n` out is an undefined behavior since it's haven't been initialized before used.

----

# Exercise 9.4

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

- It compiles since there is an `n` is with file scope and an `n` with local scope.
- The output is `6`. The inner scope hides the outer scope.

---

# Exercise 9.5

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
- It compiles and outputs `5`.


---

# Exercise 9.6

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

- It compiles.
- The output is `30`.

---

<div class="columns">
<div class="columns-left">

# Exercise 9.7

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

<br>

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
- It compiles.
- It does **NOT** link since the reference to `validate()` in `main()` is undefined because `validate()` has internal linkage.

</div>
</div>

---

# Exercise 10.1

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

- It compiles, because `account.h` is in both translation units.
- It does **NOT** link because `acct_status` has been defined in both translation units.

---

# Exercise 10.2

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

- It does **NOT** compile and you will get a message like 'acct_status' was not declared in this scope.

---

# Exercise 10.3

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

- `account.c` will compile but `driver.c` won't.

---

# Exercise 10.4

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

- They compile, because `acct_status` is declared in `account.h`.
- They do **NOT** link since `acct_status` has been declared but not defined.
  - `undefined reference to 'acct_status'`
---

# Exercise 10.5

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

- Correct implementation.

---

# Recitation 3 Code
## From Xiao Liu