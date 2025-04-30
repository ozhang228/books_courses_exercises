export type OptionType = "Call" | "Put";

export type VolatilityData = {
  id: number,
  symbol: string,
  expiry: string,
  strike: number,
  optionType: OptionType,
  impliedVolatility: number
};
