use std::time::{Duration, Instant};

fn main() {
    let now = Instant::now();

    let mut number:i64 = 600851475143;
    let sqrt_of_number = (number as f64).sqrt() as i64;
    let mut divider = 2;

    while number != 1
    {
        if divider > sqrt_of_number{
            divider = number;
            break;
        } else if number % divider == 0 {
            number /=  divider;
        } else {
            divider += 1;
        }
    }

    println!("Number: {}", divider);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
