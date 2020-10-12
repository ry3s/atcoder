let () =
  Scanf.scanf "%d %d %d " @@
    fun n x m ->
    let rec solve acc x = function
      | 0 -> acc
      | n -> solve (acc + x) (x * x mod m) (n - 1) in
    let a = Array.make m (-1) in
    let l = Array.make m (-1) in
    let rec solve' acc x = function
      | 0 -> acc
      | n -> if 0 <= a.(x)
             then solve (acc + n / (l.(x) - n) * (acc - a.(x))) x (n mod (l.(x) - n))
             else begin
                 a.(x) <- acc;
                 l.(x) <- n;
                 solve' (acc + x) (x * x mod m) (n - 1)
               end
    in
    Printf.printf "%d\n" @@ solve' 0 x n
