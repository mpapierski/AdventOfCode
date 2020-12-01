use std::{
    error::Error,
    io::{self, BufRead, BufReader},
    str::FromStr,
};

fn read_numbers(io: impl io::Read) -> Result<Vec<u64>, io::Error> {
    BufReader::new(io)
        .lines()
        .map(|line| {
            line.and_then(|v| {
                u64::from_str(&v).map_err(|e| io::Error::new(io::ErrorKind::InvalidData, e))
            })
        })
        .collect()
}

fn answer1(numbers: &[u64]) -> Option<u64> {
    for i in numbers {
        for j in numbers {
            if i + j == 2020 {
                return Some(i * j);
            }
        }
    }
    None
}

fn answer2(numbers: &[u64]) -> Option<u64> {
    for i in numbers {
        for j in numbers {
            for k in numbers {
                if i + j + k == 2020 {
                    return Some(i * j * k);
                }
            }
        }
    }
    None
}

fn main() -> Result<(), Box<dyn Error>> {
    let numbers = read_numbers(io::stdin())?;

    let part1 = answer1(&numbers).expect("should have part1 answer");
    println!("part1: {}", part1);

    let part2 = answer2(&numbers).expect("should have part2 answer");
    println!("part2: {}", part2);

    Ok(())
}

#[cfg(test)]
mod tests {
    use std::io::Cursor;

    use super::*;

    #[test]
    fn should_read_numbers() {
        let numbers = read_numbers(Cursor::new(b"1\n2\n3\n")).expect("should work");
        assert_eq!(numbers, vec![1, 2, 3]);
    }

    #[should_panic]
    #[test]
    fn should_fail_to_read_numbers() {
        read_numbers(Cursor::new(b"1\n2\n3\n\n")).unwrap();
    }

    #[should_panic]
    #[test]
    fn should_fail_to_read_numbers_2() {
        read_numbers(Cursor::new(b"a\nb\nc\n")).unwrap();
    }

    #[test]
    fn should_calculate_part1() {
        assert_eq!(answer1(&[1721, 979, 366, 299, 675, 1456]), Some(514579));
    }

    #[test]
    fn should_calculate_part2() {
        assert_eq!(
            answer2(&[5, 1010, 4, 3, 2, 1, 10, 1, 2, 3, 1000, 4, 5]),
            Some(1000 * 1010 * 10)
        );
    }
}
