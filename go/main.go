package main

import (
	"fmt"
	"strconv"
	"strings"
)

type matcher func(int) bool

func times(n int) matcher {
	return func(m int) bool {
		return m % n == 0
	}
}

func str(m int) string {
	return strconv.Itoa(m)
}

func contains(n int) matcher {
	return func(m int) bool {
		return strings.Contains(str(m), str(n))
	}
}

func always() matcher {
	return func(int) bool {
		return true
	}
}

type action func(int) string

func to(s string) action {
	return func(int) string {
		return s
	}
}

func nop() action {
	return func(m int) string {
		return strconv.Itoa(m)
	}
}

type rule func(int) string

func atom(m matcher, a action) rule {
	return func(n int) string {
		if m(n) {
			return a(n)
		}
		return ""
	}
}

func all(rules []rule) rule {
	return func(n int) (s string) {
		for _, r := range rules {
			s += r(n)
		}
		return s
	}
}

func any(rules []rule) rule {
	return func(n int) string {
		for _, r := range rules {
			if s := r(n); len(s) != 0 {
				return s
			}
		}
		return ""
	}
}

func spec(n1, n2, n3 int) rule {
	rn1 := atom(times(n1), to("Fizz"))
	rn2 := atom(times(n2), to("Bizz"))
	rn3 := atom(times(n3), to("Whizz"))

	r3 := atom(contains(n1), to("Fizz"))
	r2 := all([]rule{rn1, rn2, rn3})
	rd := atom(always(), nop())

	return any([]rule{r3, r2, rd})
}

func start(n int, saying rule) {
	for i := 1; i <= n; i++ {
		fmt.Printf("%d -> %s\n", i, saying(i))
	}
}

func main() {
	start(100, spec(3, 5, 7))
}