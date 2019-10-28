use std::time::Instant;

fn main() {
    let now = Instant::now();

    let n = 100;
    let sum_of_squares: u128 = (1..n+1).map(|x:u128| x.pow(2)).sum();
    let square_of_sum: u128 = (1..n+1).sum::<u128>().pow(2);

    println!("Difference: {}", square_of_sum-sum_of_squares);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}
