import {
  Youtube, PenTool, Twitter, Briefcase, Chrome, Video,
  Code, DollarSign, Mail, Zap, TrendingUp, Search,
  Film, Smile, Music, Image
} from "lucide-react";

export type Category = {
  id: string;
  name: string;
  icon: any;
  tools: Tool[];
};

export type Tool = {
  name: string;
  description: string;
  url: string;
};

export const categories: Category[] = [
  {
    id: "youtube", name: "YouTube Tools", icon: Youtube,
    tools: [
      { name: "TubeBuddy", description: "SEO & channel management for YouTube creators", url: "https://www.tubebuddy.com" },
      { name: "vidIQ", description: "YouTube analytics and keyword research tool", url: "https://vidiq.com" },
      { name: "Pictory", description: "Turn scripts into short branded videos", url: "https://pictory.ai" },
      { name: "Opus Clip", description: "AI-powered short clip generator from long videos", url: "https://www.opus.pro" },
      { name: "Thumbnaily", description: "AI thumbnail generator for YouTube", url: "https://thumbnaily.ai" },
      { name: "Gling", description: "Auto-edit YouTube videos, remove silences & bad takes", url: "https://www.gling.ai" },
    ],
  },
  {
    id: "writing", name: "Writing Tools", icon: PenTool,
    tools: [
      { name: "Jasper", description: "AI writing assistant for marketing content", url: "https://www.jasper.ai" },
      { name: "Copy.ai", description: "Generate marketing copy in seconds", url: "https://www.copy.ai" },
      { name: "Writesonic", description: "AI writer for blogs, ads, and product descriptions", url: "https://writesonic.com" },
      { name: "Rytr", description: "Affordable AI writing assistant", url: "https://rytr.me" },
      { name: "Grammarly", description: "AI-powered grammar and style checker", url: "https://www.grammarly.com" },
      { name: "QuillBot", description: "Paraphrasing and summarization tool", url: "https://quillbot.com" },
    ],
  },
  {
    id: "twitter", name: "Twitter Tools", icon: Twitter,
    tools: [
      { name: "Typefully", description: "Write and schedule Twitter threads", url: "https://typefully.com" },
      { name: "TweetHunter", description: "AI-powered tweet inspiration and scheduling", url: "https://tweethunter.io" },
      { name: "Hypefury", description: "Grow your Twitter audience with AI", url: "https://hypefury.com" },
      { name: "Postwise", description: "AI ghostwriter for viral tweets", url: "https://postwise.ai" },
      { name: "Tribescaler", description: "Generate hooks for Twitter threads", url: "https://tribescaler.com" },
      { name: "BlackMagic.so", description: "Twitter CRM and analytics dashboard", url: "https://blackmagic.so" },
    ],
  },
  {
    id: "management", name: "Management Tools", icon: Briefcase,
    tools: [
      { name: "Notion AI", description: "AI-enhanced workspace for docs, tasks, wikis", url: "https://www.notion.so" },
      { name: "ClickUp AI", description: "Project management with AI writing & summarization", url: "https://clickup.com" },
      { name: "Monday.com", description: "Work OS with AI-powered automations", url: "https://monday.com" },
      { name: "Reclaim.ai", description: "AI scheduling and time management", url: "https://reclaim.ai" },
      { name: "Taskade", description: "AI-powered task and project management", url: "https://www.taskade.com" },
      { name: "Mem.ai", description: "AI-powered self-organizing notes", url: "https://mem.ai" },
    ],
  },
  {
    id: "chrome", name: "Chrome Extensions", icon: Chrome,
    tools: [
      { name: "AIPRM", description: "Curated ChatGPT prompt templates", url: "https://www.aiprm.com" },
      { name: "Merlin", description: "ChatGPT Plus on all websites", url: "https://www.getmerlin.in" },
      { name: "Monica", description: "AI copilot in your browser", url: "https://monica.im" },
      { name: "Compose AI", description: "AI-powered autocompletion for emails", url: "https://www.compose.ai" },
      { name: "Wiseone", description: "AI reading companion for complex articles", url: "https://wiseone.io" },
      { name: "Harpa AI", description: "AI agent for Chrome automation", url: "https://harpa.ai" },
    ],
  },
  {
    id: "content", name: "Content Creation", icon: Video,
    tools: [
      { name: "Canva AI", description: "Design with AI-powered tools and templates", url: "https://www.canva.com" },
      { name: "Descript", description: "AI video & podcast editing platform", url: "https://www.descript.com" },
      { name: "Synthesia", description: "Create AI videos with digital avatars", url: "https://www.synthesia.io" },
      { name: "Lumen5", description: "Turn blog posts into engaging videos", url: "https://lumen5.com" },
      { name: "Kapwing", description: "AI-powered collaborative video editor", url: "https://www.kapwing.com" },
      { name: "InVideo", description: "Create professional videos with AI", url: "https://invideo.io" },
    ],
  },
  {
    id: "coding", name: "Coding Tools", icon: Code,
    tools: [
      { name: "GitHub Copilot", description: "AI pair programmer for code suggestions", url: "https://github.com/features/copilot" },
      { name: "Cursor", description: "AI-first code editor", url: "https://cursor.sh" },
      { name: "Tabnine", description: "AI code completion for all languages", url: "https://www.tabnine.com" },
      { name: "Replit AI", description: "AI-powered collaborative coding platform", url: "https://replit.com" },
      { name: "Codeium", description: "Free AI code completion and chat", url: "https://codeium.com" },
      { name: "Lovable", description: "AI full-stack web app builder", url: "https://lovable.dev" },
    ],
  },
  {
    id: "sales", name: "Sales Tools", icon: DollarSign,
    tools: [
      { name: "Gong", description: "Revenue intelligence with AI conversation analysis", url: "https://www.gong.io" },
      { name: "Apollo.io", description: "AI-powered lead gen and sales engagement", url: "https://www.apollo.io" },
      { name: "Outreach", description: "AI-driven sales execution platform", url: "https://www.outreach.io" },
      { name: "Seamless.AI", description: "Real-time contact data and lead building", url: "https://seamless.ai" },
      { name: "Lavender", description: "AI email coach for sales reps", url: "https://www.lavender.ai" },
      { name: "Regie.ai", description: "AI content platform for sales teams", url: "https://www.regie.ai" },
    ],
  },
  {
    id: "email", name: "Email Marketing", icon: Mail,
    tools: [
      { name: "Mailchimp AI", description: "AI-powered email campaigns and automation", url: "https://mailchimp.com" },
      { name: "Beehiiv", description: "Newsletter platform with AI writing tools", url: "https://www.beehiiv.com" },
      { name: "Smartwriter", description: "AI cold email personalization", url: "https://www.smartwriter.ai" },
      { name: "Instantly", description: "AI-powered cold email outreach at scale", url: "https://instantly.ai" },
      { name: "Seventh Sense", description: "AI email delivery optimization", url: "https://www.theseventhsense.com" },
      { name: "Phrasee", description: "AI-generated email subject lines & copy", url: "https://phrasee.co" },
    ],
  },
  {
    id: "productivity", name: "Productivity", icon: Zap,
    tools: [
      { name: "Otter.ai", description: "AI meeting notes and transcription", url: "https://otter.ai" },
      { name: "Fireflies.ai", description: "AI notetaker for meetings", url: "https://fireflies.ai" },
      { name: "Bardeen", description: "AI-powered workflow automation", url: "https://www.bardeen.ai" },
      { name: "Tldv", description: "Record, transcribe, and summarize meetings", url: "https://tldv.io" },
      { name: "SaneBox", description: "AI email management and filtering", url: "https://www.sanebox.com" },
      { name: "Krisp", description: "AI noise cancellation for calls", url: "https://krisp.ai" },
    ],
  },
  {
    id: "marketing", name: "Marketing", icon: TrendingUp,
    tools: [
      { name: "HubSpot AI", description: "AI-powered CRM and marketing automation", url: "https://www.hubspot.com" },
      { name: "Persado", description: "AI-generated marketing language", url: "https://www.persado.com" },
      { name: "Albert.ai", description: "Autonomous AI marketing platform", url: "https://albert.ai" },
      { name: "Anyword", description: "AI copywriting with predictive analytics", url: "https://anyword.com" },
      { name: "Pathmatics", description: "AI digital ad intelligence", url: "https://www.pathmatics.com" },
      { name: "Crayon", description: "AI competitive intelligence platform", url: "https://www.crayon.co" },
    ],
  },
  {
    id: "seo", name: "SEO Tools", icon: Search,
    tools: [
      { name: "Surfer SEO", description: "AI-powered on-page SEO optimization", url: "https://surferseo.com" },
      { name: "Clearscope", description: "AI content optimization for SEO", url: "https://www.clearscope.io" },
      { name: "Frase", description: "AI SEO content research and writing", url: "https://www.frase.io" },
      { name: "MarketMuse", description: "AI content strategy and planning", url: "https://www.marketmuse.com" },
      { name: "NeuronWriter", description: "SEO content editor with AI suggestions", url: "https://neuronwriter.com" },
      { name: "SE Ranking", description: "All-in-one SEO platform with AI features", url: "https://seranking.com" },
    ],
  },
  {
    id: "video", name: "Video Editing", icon: Film,
    tools: [
      { name: "Runway", description: "AI-powered creative video editing suite", url: "https://runwayml.com" },
      { name: "HeyGen", description: "AI video generation with talking avatars", url: "https://www.heygen.com" },
      { name: "Veed.io", description: "Online video editor with AI features", url: "https://www.veed.io" },
      { name: "Fliki", description: "Turn text into videos with AI voices", url: "https://fliki.ai" },
      { name: "Colossyan", description: "AI video creation for workplace learning", url: "https://www.colossyan.com" },
      { name: "Elai.io", description: "Text-to-video with AI presenters", url: "https://elai.io" },
    ],
  },
  {
    id: "daily", name: "Daily Life Tools", icon: Smile,
    tools: [
      { name: "ChatGPT", description: "Versatile AI assistant for any task", url: "https://chat.openai.com" },
      { name: "Perplexity", description: "AI-powered search engine with citations", url: "https://www.perplexity.ai" },
      { name: "Claude", description: "Thoughtful AI assistant by Anthropic", url: "https://claude.ai" },
      { name: "Gemini", description: "Google's multimodal AI assistant", url: "https://gemini.google.com" },
      { name: "Character.ai", description: "Chat with AI-generated characters", url: "https://character.ai" },
      { name: "Replika", description: "AI companion for conversation", url: "https://replika.com" },
    ],
  },
  {
    id: "music", name: "Music Tools", icon: Music,
    tools: [
      { name: "Suno", description: "Generate original songs with AI", url: "https://suno.com" },
      { name: "Udio", description: "AI music generation platform", url: "https://www.udio.com" },
      { name: "AIVA", description: "AI composer for emotional soundtrack music", url: "https://www.aiva.ai" },
      { name: "Soundraw", description: "AI music generator for creators", url: "https://soundraw.io" },
      { name: "Boomy", description: "Create original songs in seconds", url: "https://boomy.com" },
      { name: "Mubert", description: "AI-generated royalty-free music", url: "https://mubert.com" },
    ],
  },
  {
    id: "image", name: "Image Tools", icon: Image,
    tools: [
      { name: "Midjourney", description: "AI art generation from text prompts", url: "https://www.midjourney.com" },
      { name: "DALL·E 3", description: "OpenAI's advanced image generation", url: "https://openai.com/dall-e-3" },
      { name: "Stable Diffusion", description: "Open-source AI image generation", url: "https://stability.ai" },
      { name: "Leonardo.ai", description: "AI image generation for creative projects", url: "https://leonardo.ai" },
      { name: "Remove.bg", description: "AI background removal in one click", url: "https://www.remove.bg" },
      { name: "Photoroom", description: "AI photo editor for product images", url: "https://www.photoroom.com" },
    ],
  },
];
