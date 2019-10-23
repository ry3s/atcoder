let (h, w) = Scanf.scanf "%d %d" (fun a b -> a, b);;
let quotient = (h * w) / 3;;
let remainder = (h * w) mod 3;;
let (maxi, mini) =
  if remainder = 0 && (quotient mod 2 = 0) then
    (quotient, quotient)
  else
    (quotient + remainder, quotient);;

let () = Printf.printf "%d\n" (maxi - mini);;
