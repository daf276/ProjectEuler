use std::time::{Duration, Instant};

fn is_palindrom(potential_palindrom: i32) -> bool{
    let potential_palindrom_string = potential_palindrom.to_string();

    for (c1, c2) in potential_palindrom_string.chars().zip(potential_palindrom_string.chars().rev()) {
        if c1 != c2 {
            return false;
        }
    }

    return true;
}

fn main() {
    let now = Instant::now();

    let mut largest_palindrom = 0;

    for i in 100..1000 {
        for j in 100..1000 {
            if is_palindrom(i * j) && i * j > largest_palindrom{
                largest_palindrom = i * j;
            }
        }
    }

    println!("Largest Palindrom: {}", largest_palindrom);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
