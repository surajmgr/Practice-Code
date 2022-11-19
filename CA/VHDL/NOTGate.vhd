library ieee;
use ieee.std_logic_1164.all;
 
entity not_gate is
  port (
    input_1    : in  std_logic;
  
    not_result : out std_logic
    );
end not_gate;
 
architecture rtl of not_gate is
begin
  not_result   <= not input_1;
end rtl;
