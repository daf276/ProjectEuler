use std::time::Instant;
use std::fs;
use std::cmp;

const GRID_SIZE: usize = 20;
const PRODUCT_LENGTH: usize = 4;

struct Vec2D {
    vec: Vec<i32>,
    row_length: usize,
}

impl Vec2D {
    fn new(vec: Vec<i32>, row_length: usize) -> Vec2D {
        Vec2D {
            vec: vec,
            row_length: row_length,
        }
    }

    fn element_at(&self, x: i32, y: i32) -> i32 {
        return self.vec[(y as usize) * self.row_length + (x as usize)];
    }
}

fn main() {
    let now = Instant::now();

    let input = fs::read_to_string("numbers.txt").expect("Something went wrong reading the file");

    let input_as_vec: Vec2D = Vec2D::new(input.split_whitespace().map(|x|
        i32::from_str_radix(x, 10)).filter_map(Result::ok).collect(), GRID_SIZE);

    let stride_sum = |x: usize, y: usize, x_stride: i32, y_stride: i32| {
        let mut answer = 1;

        for i in 0..PRODUCT_LENGTH {
            let x_pos = (x as i32) + x_stride * (i as i32);
            let y_pos = (y as i32) + y_stride * (i as i32);
            answer *= input_as_vec.element_at(x_pos, y_pos);
        }

        return answer;
    };

    let mut greatest_product = 0;

    for y in 0..GRID_SIZE {
        for x in 0..GRID_SIZE {
            if y <= (GRID_SIZE - PRODUCT_LENGTH) {
                //Down
                greatest_product = cmp::max(stride_sum(x, y, 0, 1), greatest_product);

                if x <= (GRID_SIZE - PRODUCT_LENGTH) {
                    //Down+Right
                    greatest_product = cmp::max(stride_sum(x, y, 1, 1), greatest_product);
                }

                if x >= (PRODUCT_LENGTH - 1) {
                    //Down+Left
                    greatest_product = cmp::max(stride_sum(x, y, -1, 1), greatest_product);
                }
            }

            //Right
            if x <= (GRID_SIZE - PRODUCT_LENGTH) {
                greatest_product = cmp::max(stride_sum(x, y, 1, 0), greatest_product);
            }
        }
    }

    println!("Product: {}", greatest_product);
    println!("Elapsed µs: {}", now.elapsed().as_micros());
}