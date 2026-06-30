use unicode_reverse::reverse_grapheme_clusters_in_place;

pub fn reverse(input: &str) -> String {
    let mut input_string = input.to_owned();

    reverse_grapheme_clusters_in_place(&mut input_string);

    input_string
}
