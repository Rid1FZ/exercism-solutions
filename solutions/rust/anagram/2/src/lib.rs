use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let word_lower = word.to_lowercase();

    let mut word_sorted = word_lower.chars().collect::<Vec<char>>();
    word_sorted.sort_unstable();

    possible_anagrams
        .iter()
        .filter(|&&candidate| {
            let candidate_lower = candidate.to_lowercase();

            if candidate_lower == word_lower {
                return false;
            }

            if candidate_lower.len() != word_lower.len() {
                return false;
            }

            let mut candidate_sorted = candidate_lower.chars().collect::<Vec<char>>();
            candidate_sorted.sort_unstable();

            candidate_sorted == word_sorted
        })
        .copied()
        .collect()
}
