let board =
  Array.init 4 (fun _ ->
      Array.init 4 (fun _ ->
          Scanf.scanf " %c" (fun x -> x)))
let () =
  for y = 0 to 3 do
    for x = 0 to 3 do
      Printf.printf "%c " board.(3 - y).(3 - x)
    done;
    print_newline ()
  done;
