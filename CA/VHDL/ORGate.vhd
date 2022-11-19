library ieee;
use ieee.std_logic_1164.all;
 
entity or_gate is
  port (
    input_1    : in  std_logic;
    input_2    : in  std_logic;
    or_result : out std_logic
    );
end or_gate;
 
architecture rtl of or_gate is
  
begin
  or_result   <= input_1 or input_2;
end rtl;
