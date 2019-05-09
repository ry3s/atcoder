let () =
  let n = Scanf.scanf "%d " (fun x -> x) in
  let spot = Array.init n (fun _ ->
                 Scanf.scanf " %d" (fun x -> x)) in
  let sum =
    let rec loop i sum arr =
      if i = 0 then
        loop (i+1) (sum + abs (0 - arr.(i))) arr
      else
        begin
        if i = n then
          sum + (abs (arr.(n-1) - 0))
        else
          loop (i+1) (sum + abs (arr.(i-1) - arr.(i))) arr
        end
    in
    loop 0 0 spot
  in
  (* Printf.printf "%d\n" sum *) 
  for i = 0 to (n-1) do
    Printf.printf "%d\n"
      (sum +
         (if i = n-1 then
            - abs (spot.(n-2) - spot.(n-1))
            - abs (spot.(n-1) - 0)
            + abs (spot.(n-2) - 0)
          else
            (if i = 0 then
               - abs (spot.(0) - 0)
               - abs (spot.(0) - spot.(1))
               + abs (spot.(1) - 0)
             else
               - abs (spot.(i-1) - spot.(i))
               - abs (spot.(i) - spot.(i+1))
               + abs (spot.(i-1) - spot.(i+1)) )))
  done;
  
