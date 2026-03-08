import { type Tool } from "@/data/aiTools";
import { Bot, ExternalLink } from "lucide-react";

type ToolCardProps = {
  tool: Tool;
  index: number;
};

const ToolCard = ({ tool, index }: ToolCardProps) => {
  return (
    <a
      href={tool.url}
      target="_blank"
      rel="noopener noreferrer"
      className="glass-card hover-glow p-5 group animate-fade-in opacity-0 block cursor-pointer"
      style={{ animationDelay: `${index * 0.03}s` }}
    >
      <div className="flex items-start gap-3">
        <div className="w-10 h-10 rounded-lg bg-primary/10 flex items-center justify-center shrink-0 group-hover:bg-primary/20 transition-colors">
          <Bot className="w-5 h-5 text-primary" />
        </div>
        <div className="flex-1">
          <div className="flex items-center justify-between">
            <h3 className="font-display font-semibold text-foreground group-hover:text-primary transition-colors">
              {tool.name}
            </h3>
            <ExternalLink className="w-4 h-4 text-muted-foreground opacity-0 group-hover:opacity-100 transition-opacity" />
          </div>
          <p className="text-sm text-muted-foreground mt-1 leading-relaxed">
            {tool.description}
          </p>
        </div>
      </div>
    </a>
  );
};

export default ToolCard;
