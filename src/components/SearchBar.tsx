import { Search } from "lucide-react";

type SearchBarProps = {
  value: string;
  onChange: (val: string) => void;
};

const SearchBar = ({ value, onChange }: SearchBarProps) => {
  return (
    <div className="relative max-w-xl mx-auto">
      <Search className="absolute left-4 top-1/2 -translate-y-1/2 w-5 h-5 text-muted-foreground" />
      <input
        type="text"
        placeholder="Search tools or categories..."
        value={value}
        onChange={(e) => onChange(e.target.value)}
        className="w-full pl-12 pr-4 py-3.5 rounded-xl bg-input border border-border/50 text-foreground placeholder:text-muted-foreground focus:outline-none focus:ring-2 focus:ring-primary/40 focus:border-primary/50 transition-all font-body"
      />
    </div>
  );
};

export default SearchBar;
