library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
entity SignedTest1 is
				port(in1, in2 : in unsigned(3 downto 0);
			     out1 : out unsigned(3 downto 0));
end SignedTest1;
architecture Behavioral of SignedTest1 is
begin
  out1 <= in1 + in2;
end Behavioral;