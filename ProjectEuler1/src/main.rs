use std::time::{Duration, Instant};

fn main() {
    let now = Instant::now();
    let mut sum = 0;

    for i in 3..1000 {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i;
        }
    }

    println!("Sum: {}", sum);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
