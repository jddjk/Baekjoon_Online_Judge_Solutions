use std::io::{self, BufRead};

fn solve(x1: i64, y1: i64, r1: i64, x2: i64, y2: i64, r2: i64) {
    let distance_pow = (x1 - x2).pow(2) + (y1 - y2).pow(2);
    let add_r_pow = (r1 + r2).pow(2);
    let sub_r_pow = (r1 - r2).pow(2);

    if distance_pow == 0 {
        if r1 == r2 {
            if r1 == 0 && r2 == 0 {
                println!("1");
            } else {
                println!("-1");
            }
        } else {
            println!("0");
        }
    } else if distance_pow == add_r_pow || distance_pow == sub_r_pow {
        println!("1");
    } else if sub_r_pow < distance_pow && distance_pow < add_r_pow {
        println!("2");
    } else {
        println!("0");
    }
}

fn main() {
    let stdin = io::stdin();
    let mut iter = stdin.lock().lines().map(|l| l.unwrap());
    let t: i32 = iter.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let line = iter.next().unwrap();
        let nums: Vec<i64> = line
            .split_whitespace()
            .map(|num| num.parse().unwrap())
            .collect();
        solve(nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
    }
}
