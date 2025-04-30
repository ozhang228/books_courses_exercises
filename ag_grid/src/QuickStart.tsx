import { useState } from "react";
import { AgGridReact } from "ag-grid-react";
import type { ColDef } from "ag-grid-community";

interface RowData {
  make: string,
  model: string,
  price: number,
  electric: boolean
}

export default function QuickStart() {

  // Row Data: The data to be displayed.
  const [rowData,] = useState<RowData[]>([
    { make: "Tesla", model: "Model Y", price: 64950, electric: true },
    { make: "Ford", model: "F-Series", price: 33850, electric: false },
    { make: "Toyota", model: "Corolla", price: 29600, electric: false },
  ]);

  // Column Definitions: Defines the columns to be displayed.
  const [colDefs,] = useState<ColDef<RowData>[]>([
    { field: "make" },
    { field: "model" },
    { field: "price" },
    { field: "electric" }
  ]);

  return (
    <div className="h-[200px]">
      <AgGridReact
        rowData={rowData}
        columnDefs={colDefs}
      />
    </div>
  );
};
