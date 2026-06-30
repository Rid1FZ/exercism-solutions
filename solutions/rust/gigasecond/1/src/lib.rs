use time::Duration;
use time::PrimitiveDateTime as DateTime;

pub fn after(start: DateTime) -> DateTime {
    let gigasec = Duration::seconds_f64(1_000_000_000.0f64);
    start + gigasec
}
