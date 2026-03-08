import { type Tool } from "@/data/aiTools";
import { Bot } from "lucide-react";

type ToolCardProps = {
  tool: Tool;
  index: number;
};

const ToolCard = ({ tool, index }: ToolCardProps) => {
  return (
    <div
      className="glass-card hover-glow p-5 group animate-fade-in opacity-0"
      style={{ animationDelay: `${index * 0.03}s` }}
    >
      <div className="flex items-start gap-3">
        <div className="w-10 h-10 rounded-lg bg-primary/10 flex items-center justify-center shrink-0 group-hover:bg-primary/20 transition-colors">
          <Bot className="w-5 h-5 text-primary" />
        </div>
        <div>
          <h3 className="font-display font-semibold text-foreground group-hover:text-primary transition-colors">
            {tool.name}
          </h3>
          <p className="text-sm text-muted-foreground mt-1 leading-relaxed">
            {tool.description}
          </p>
        </div>
      </div>
    </div>
  );
};

export default ToolCard;
