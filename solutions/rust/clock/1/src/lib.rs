use std::fmt;

#[derive(PartialEq, Eq, Debug)]
pub struct Clock {
    hour: u32,
    minutes: u32,
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:02}:{:02}", self.hour, self.minutes)
    }
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        const SEC_IN_DAY: i32 = 86400; // 60*60*24

        let mut sec = (hours as i64) * 60 * 60 + (minutes as i64) * 60;
        sec %= SEC_IN_DAY as i64;

        if sec < 0 {
            sec += SEC_IN_DAY as i64;
        }

        Self {
            hour: ((sec / 3600) as u32),
            minutes: (((sec % 3600) / 60) as u32),
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        let hours = self.hour as i32;
        let minutes = (self.minutes) as i32 + minutes;

        Self::new(hours, minutes)
    }
}
