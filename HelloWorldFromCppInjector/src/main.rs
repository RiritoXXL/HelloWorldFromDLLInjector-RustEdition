use dll_syringe::{Syringe, process::OwnedProcess};
fn main() {
    let targetproc = OwnedProcess::find_first_by_name("explorer").unwrap();
    let syr = Syringe::for_process(targetproc);
    syr.inject("HelloWorldFromCppDLL.dll").unwrap();
    println!("Hello World from DLL Injector!!!");
}
