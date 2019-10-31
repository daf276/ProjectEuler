use std::time::{Duration, Instant};

fn main() {
    let now = Instant::now();
    let mut sum:i32 = (3..1000).filter(|&x| x % 3 == 0 || x % 5 == 0).sum();

    println!("Sum: {}", sum);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
