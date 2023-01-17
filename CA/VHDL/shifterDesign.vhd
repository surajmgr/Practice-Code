-- The input/ output interface of the shifter is shown in the above figure. The shifter instruction set is as follows:
-- 	•	SHIFT_Ctrl = "1000": SHIFTOUT <= Rotate SHIFTINPUT >>8
-- 	•	SHIFT_Ctrl = "1001": SHIFTOUT <= Rotate SHIFTINPUT >>4
-- 	•	SHIFT_Ctrl = "1010": SHIFTOUT <= Shift Left Logical SHIFTINPUT << 8

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity shifter is
    Port ( SHIFTINPUT : in  STD_LOGIC_VECTOR(15 downto 0);
   SHIFT_Ctrl : in  STD_LOGIC_VECTOR(3 downto 0); 
   SHIFTOUT: out  STD_LOGIC_VECTOR(15 downto 0)
  );
end shifter;

architecture Behavioral of shifter is
begin
process(SHIFTINPUT,SHIFT_Ctrl)
begin
case(SHIFT_Ctrl) is
when "1000" => SHIFTOUT <= SHIFTINPUT(7 downto 0)&SHIFTINPUT(15 downto 8);
when "1001" => SHIFTOUT <= SHIFTINPUT(3 downto 0)&SHIFTINPUT(15 downto 4);
when "1010" => SHIFTOUT <= SHIFTINPUT(7 downto 0) & "00000000"; 
when others => SHIFTOUT <= "00000000";
end case;
end process;

end Behavioral;