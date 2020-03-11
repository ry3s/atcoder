let s = Scanf.scanf "%s" (fun s -> s)
let () =
  String.lowercase s
  |> String.capitalize
  |> print_endline
