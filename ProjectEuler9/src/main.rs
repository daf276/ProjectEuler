use std::time::Instant;

fn main() {
    let now = Instant::now();

    let y = 1000;
    let mut a = 0;
    let mut b = 0;
    let mut c= 0;

    'outer: for i in 1..=y/3 {
        for j in 1..=y/2  {
            let potential_c = (((i as i32).pow(2) + (j as i32).pow(2)) as f64).sqrt();

            if potential_c.floor() == potential_c {
                if i + j + (potential_c as i32) == y {
                    a = i as i32;
                    b = j as i32;
                    c = potential_c as i32;
                    break 'outer;
                }
            }
        }
    }

    println!("Product: {}", a*b*c);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}