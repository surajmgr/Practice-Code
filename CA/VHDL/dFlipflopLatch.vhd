Library ieee;

Use ieee.std_logic_1164.all;

entity d_latch is
  port (c,d : in std_logic;
        q,nq : out std_logic);
end d_latch;

architecture arch of d_latch is

Signal qt, nqt: std_logic;

begin  

  qt <= (d nand c) nand nqt;
  nqt <= ((not d) nand c) nand qt;

  q <= qt;
  nq <= nqt;

end arch;