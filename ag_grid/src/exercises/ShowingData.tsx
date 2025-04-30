import { AgGridReact, CustomCellRendererProps } from "ag-grid-react";
import type { ColDef } from "ag-grid-community";
import { sampleData } from "./sampleData";
import { VolatilityData } from "./types";

const StrikeCol = (props: CustomCellRendererProps) => {
  return <strong>{props.value}</strong>
};

export default function ShowingData() {
  const colDef: ColDef<VolatilityData>[] = [
    { field: "id", flex: 5 },
    { field: "symbol", valueFormatter: p => p.data ? p.data.symbol + "!" : "" },
    { headerName: "Expiry Month", valueGetter: p => p.data ? p.data.expiry.substring(5, 7) : "" },
    { field: "strike", cellRenderer: StrikeCol }
  ];

  return <div className="h-screen">
    <AgGridReact
      rowData={sampleData}
      columnDefs={colDef}
    ></AgGridReact>
  </div>
}
