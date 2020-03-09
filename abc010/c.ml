let txa, tya, txb, tyb, t, v =
  Scanf.scanf " %d %d %d %d %d %d" (fun a b c d e f -> (a, b, c, d, e, f))
let n = Scanf.scanf " %d" (fun x -> x)
let arr = Array.to_list @@ Array.init n
          @@ fun _ ->  Scanf.scanf " %d %d" (fun x y -> (x, y))
let ans = List.exists (fun (x, y) ->
              let dist1 = sqrt @@ (float (x - txa)) ** 2.
                                  +. (float (y - tya)) ** 2. in
              let dist2 = sqrt @@ (float (x - txb)) ** 2.
                                  +. (float (y - tyb)) ** 2. in
              (dist1 +. dist2) <= float (t * v)
            ) arr
let () = Printf.printf "%s\n" (if ans then "YES" else "NO")
