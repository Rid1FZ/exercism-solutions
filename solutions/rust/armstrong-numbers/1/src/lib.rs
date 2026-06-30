pub fn is_armstrong_number(num: u32) -> bool {
    if num == 0 {
        return true;
    }

    let digits = num.ilog10() + 1;

    let mut sum = 0u64;
    let mut temp = num;

    while temp > 0 {
        let digit = (temp % 10) as u64;
        sum += digit.pow(digits);
        temp /= 10;
    }

    sum == num as u64
}
