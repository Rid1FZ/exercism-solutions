use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let word_lower = word.to_lowercase();
    let mut word_sorted: Vec<char> = word_lower.chars().collect();
    word_sorted.sort_unstable();

    possible_anagrams
        .iter()
        .filter(|&candidate| {
            let cand_lower = candidate.to_lowercase();

            if cand_lower == word_lower {
                return false;
            }

            if cand_lower.len() != word_lower.len() {
                return false;
            }

            let mut cand_sorted: Vec<char> = cand_lower.chars().collect();
            cand_sorted.sort_unstable();

            cand_sorted == word_sorted
        })
        .copied()
        .collect()
}
