import { useState } from "react";
import { AgGridReact } from "ag-grid-react";
import type { ColDef } from "ag-grid-community";
import { sampleData } from "./sampleData";
import { VolatilityData } from "./types";


export default function QuickStart() {
  // Column Definitions: Defines the columns to be displayed.
  const [colDefs,] = useState<ColDef<VolatilityData>[]>([
    { field: "id" },
    { field: "symbol" },
    { field: "expiry" },
    { field: "strike" },
    { field: "optionType" },
    { field: "impliedVolatility" }
  ]);

  return (
    <div className="h-screen">
      <AgGridReact
        rowData={sampleData}
        columnDefs={colDefs}
      />
    </div>
  );
};
