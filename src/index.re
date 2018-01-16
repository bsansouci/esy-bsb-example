/**
 * Simple example project that uses the default example on the alcotest repo
 * https://github.com/mirage/alcotest#examples 
 * 
 */

/* A module with functions to test */
module To_test = {
  let capit = (letter) => Char.uppercase_ascii(letter);
  let plus = (int_list) => List.fold_left((a, b) => a + b, 0, int_list);
};

/* The tests */
let capit = () => Alcotest.(check(char))("same chars", 'A', To_test.capit('a'));

let plus = () => Alcotest.(check(int))("same ints", 7, To_test.plus([1, 1, 2, 3]));

let test_set = [("Capitalize", `Quick, capit), ("Add entries", `Slow, plus)];

/* Run it */
let () = Alcotest.run("My first test", [("test_set", test_set)]);

