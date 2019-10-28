use std::time::{Duration, Instant};

fn gcd(mut a: i32, mut b: i32) -> i32 {
    let mut t;

    while b != 0 {
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}

fn lcm(a: i32, b: i32) -> i32 {
    a*b/gcd(a,b)
}

fn main() {
    let now = Instant::now();

    let mut x = 2;
    let mut y;

    for i in 3..20 {
        y = i;
        x = lcm(x, y);
    }

    println!("Number: {}", x);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
